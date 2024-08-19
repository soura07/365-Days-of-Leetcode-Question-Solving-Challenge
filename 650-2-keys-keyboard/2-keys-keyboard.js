/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    if (n === 1) return 0;

    const findMinSteps = (currentLength, clipboardLength) => {
        if (currentLength === n) return 0;
        if (currentLength > n) return Number.MAX_SAFE_INTEGER / 2;

        const copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength);
        const pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength);

        return Math.min(copyAndPaste, pasteOnly);
    };

    return 1 + findMinSteps(1, 1);
};