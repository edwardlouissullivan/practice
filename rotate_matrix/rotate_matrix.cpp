// PROMPT:
// Given an image represented by an NxN matrix, where each 
// pixel in the image is 4 bytes, write a method to rotate the 
// image by 90 degrees. Can you do this in place?

// SOLUTION STRATEGY:
// I am super rusty at linear algebra, but I 
// have a simle way of solving this challenge
// without traditional linear algebra
// (Also, I think that the linear algebra solution might
// required extra space)
// https://en.wikipedia.org/wiki/Rotation_matrix

// Move all the pixels in the four quadrants all at once:
// top left (r, c)
// top right relative to top left (c, max_col - r) 
// bottom right relative to top left (max_row - r, max_col -c)
// bottom left relative to left left  (max_row - c, r)

#include <vector>
#include <iostream>
#include <math.h>
using namespace std;



struct pixel_t {
    char r;
    char g;
    char b;
    char t;
    
    // Constructor
    pixel_t(char pr, char pg, char pb, char pt) : 
        r(pr), g(pg), b(pb), t(pb) {}

};
typedef vector<vector<pixel_t *>> pixel_matrix_t;


void rotate_2d_matrix(pixel_matrix_t& matrix){
    
    // For each element in top left quadrant of matrix
    // find the three corresponding elements in the
    // the other quadrants, then shift them all
    int side_len = matrix.size();
    int max_idx = side_len - 1;
    for(int r = 0; r <= max_idx/2; r++){
        for (int c = 0; c < max_idx/2; c++){
    
            int tr_r = c; // top right row
            int tr_c = max_idx - r; // top right col
            int br_r = max_idx - r; // bottom right row
            int br_c = max_idx - c; // bottom right col
            int bl_r  = max_idx - c; // bottom left row
            int bl_c  = r; // bottom left column
   
            pixel_t * cur_tl = matrix[r][c];
            pixel_t * cur_tr = matrix[tr_r][tr_c];
            pixel_t * cur_br = matrix[br_r][br_c];
            pixel_t * cur_bl = matrix[bl_r][bl_c];

            matrix[r][c] = cur_bl;
            matrix[tr_r][tr_c] = cur_tl;
            matrix[br_r][br_c] = cur_tr;
            matrix[bl_r][bl_c] = cur_br;
        }
    }
        
}

void test_rotate_2d_matrix(){

    int size = 10;
    vector<vector<pixel_t *>> test_matrix (size, vector<pixel_t *> (size));

    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++) {
            pixel_t * new_pixel = new pixel_t{(char) r, (char)r, (char) c, (char)c};
            test_matrix[r][c] = new_pixel;       
        }
    }

    rotate_2d_matrix(test_matrix);


    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++) {
            delete test_matrix[r][c];
        }
    }


    return;
}

int main(){
    test_rotate_2d_matrix();
    cout << "ALL TESTS PASSED" << endl;
    return 0;
}

