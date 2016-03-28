// Write a method that returns all subsets of a set

var allSubsets = function (set) {

    if (set.length === 1) {
        return [[set[0]]];
    }

    var subsets = [];
    var smaller = allSubsets(set.slice(1));
    var clone = smaller.map(function (val) {
        var cpy = val.slice(0);
        cpy.push(set[0]);
        return cpy;
    });
    return subsets.concat(smaller).concat(clone).concat([[set[0]]]);
};

console.log(allSubsets([1, 2, 3]));
console.log(allSubsets([1, 2, 3, 4, 5, 6]));

