// Write a method to compute all permutations of a string.

var getStringPermutations = function (str) {

    if (str.length === 1) return [str];
    
    var permutations = [];
    var subPermutations = getStringPermutations(str.slice(1));
    for (var i = 0; i < subPermutations.length; i++) {
        var substring = subPermutations[i];
        for (var j = 0; j < substring.length + 1; j++) {
            permutations.push(substring.slice(0, j) + str[0] + substring.slice(j));
        }
    }

    return permutations;
};

console.log(getStringPermutations('abcde'));

