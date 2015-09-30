var Assert = require('assert');

// Imagine a robot sitting on the upper left hand corner of an NxN grid 
// The robot can only move in two directions: right and down How many 
// possible paths are there for the robot?

// - Represent position on arbitrary grid by point object 
// - n is width/height of grid
// - If it's in the last square, it can't go anywhere
// - If it's in the one from last, it can go one place
// - Otherwise it's the sum of going right and down 

var howManyPaths = function (n, point) {

    var finalSquare = n - 1;
    point = point || {x: 0, y: 0};
    var x = point.x;
    var y = point.y;

    if (x === finalSquare && y === finalSquare) {
        return 0;
    }
    
    if (x === finalSquare || y === finalSquare) {
        return 1;
    }

    return howManyPaths(n, { x: x, y: y + 1}) + 
           howManyPaths(n, { x: x + 1, y: y});
};

Assert(howManyPaths(1) === 0);
Assert(howManyPaths(2) === 2);
Assert(howManyPaths(3) === 6);
Assert(howManyPaths(10) === 48620);

// Imagine certain squares are “off limits”, such that the robot can not
// step on them Design an algorithm to get all possible paths for the robot

var howManyPaths = function (n, offlimits, point) {

    var finalSquare = n - 1;
    point = point || {x: 0, y: 0};
    var x = point.x;
    var y = point.y;

    if (x === finalSquare && y === finalSquare) {
        return 0;
    }
    
    if (x === finalSquare || y === finalSquare) {
        return 1;
    }

    return howManyPaths(n, { x: x, y: y + 1}) + 
           howManyPaths(n, { x: x + 1, y: y});
};

Assert(howManyPaths(3, [ {x: 1, y: 1} ] ) === 6);