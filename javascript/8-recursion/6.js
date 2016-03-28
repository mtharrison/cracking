// Implement the “paint fill” function that one might see on many image editing pro- grams. That is, given a screen (represented by a 2 dimensional array of Colors), a point, and a new color, fill in the surrounding area until you hit a border of that color
// 
// I will represent an image as a 2d array of colors. Each element in the array will be a number (1 or 0 - black or white)

var image = [
    [1, 1, 0, 1, 1],
    [0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1],
    [1, 1, 0, 1, 1]
];

var fill = function (image, point, color, replacementColor) {

    if (typeof image[point[0]] !== 'undefined' && 
        typeof image[point[0]][point[1]] !== 'undefined' && 
        image[point[0]][point[1]] !== color) {
        image[point[0]][point[1]] = color;

        image = fill(image, [point[0] + 1, point[1]], color);
        image = fill(image, [point[0], point[1] + 1], color);
        image = fill(image, [point[0] - 1, point[1]], color);
        image = fill(image, [point[0], point[1] - 1], color);
    } 

    return image;
};

console.log(fill(image, [0,2], 1));

console.log(numOps);