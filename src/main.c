/*
** EPITECH PROJECT, 2023
** Fast Corner Detectors
** File description:
** main example file for the FAST corner detector
*/

#include <stdlib.h>
#include "fast.h"

typedef struct imgRawImage_s {
    unsigned int numComponents;
    unsigned long int width, height;

    unsigned char *lpData;
} imgRawImage_t;

int main(void)
{
    // Load your image data (as unsigned char *data) and set the dimensions.
    int threshold = 20;  // You can adjust this threshold as needed
    imgRawImage_t inputImage;  // Assume you have your input image
    imgRawImage_t *grayscaleImage = NULL;  // Pointer to store the grayscale image

    // Convert the input image to grayscale
    filterGrayscale(&inputImage, &grayscaleImage);

    // Now you can use the grayscaleImage with the FAST corner detection function
    int numcorners;
    xy *corners = fast9_detect_nonmax(grayscaleImage->lpData, grayscaleImage->width, grayscaleImage->height, grayscaleImage->width, threshold, &numcorners);

    // Now, 'corners' contains an array of xy structs with detected corner coordinates.
    // The 'numcorners' variable holds the number of detected corners.

    // Iterate through the detected corners and mark them as red
    for (int i = 0; i < numcorners; i++) {
        int x = corners[i].x;
        int y = corners[i].y;

        // Check if the x and y coordinates are within the image boundaries
        if (x >= 0 && x < grayscaleImage->width && y >= 0 && y < grayscaleImage->height) {
            // Assuming that lpData stores pixel values as [R, G, B] triplets
            int index = (y * grayscaleImage->width + x) * 3;

            // Set the R component to 255 (red)
            grayscaleImage->lpData[index] = 255;
            // Set the G and B components to 0 (no green or blue)
            grayscaleImage->lpData[index + 1] = 0;
            grayscaleImage->lpData[index + 2] = 0;
        }
    }

    // Don't forget to free memory when you're done
    free(corners);
    free(grayscaleImage->lpData);
    free(grayscaleImage);

    return 0;
}
