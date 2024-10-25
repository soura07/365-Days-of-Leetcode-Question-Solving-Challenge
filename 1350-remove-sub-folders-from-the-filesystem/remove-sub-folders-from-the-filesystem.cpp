class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> arr;
        unordered_map<string, bool> hash;
        for (string path: folder) {
            string temp = "";
            bool check = true;

            for (int i=0; i<path.size(); i++) {
                if(path[i]=='/') {
                    if (hash.find(temp) != hash.end()) {
                        check = false;
                    }
                }
                temp = temp + path[i];
            }

            if (check) {
                hash[temp] = true;
                arr.push_back(temp);
            }
        }
        return arr;
    }
};