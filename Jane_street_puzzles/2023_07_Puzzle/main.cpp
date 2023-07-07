/* *********************************************
* Given a m x n ...
* If we shade a subset of the cells in the above grid, we partition the cells into orthogonally connected regions of shaded and unshaded cells. The goal of this puzzle is to shade the cells so that
*   * all regions of shaded cells are rectangular,
*   * all regions of unshaded cells are not rectangular, and
*   * all number clues in the grid give the size of the region (shaded and unshaded) that the clue is in.
* The answer to this puzzle is the product of the number os unshaded cells in each row.
*   ******************************************** */
// {' ', '6', ' ', ' ', ' ', ' ', ' '}
#include <iostream>

void grid() {
    char grid_data[7][7] = {
        {' ', '6', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '3'},
        {' ', ' ', ' ', '3', ' ', ' ', ' '},
        {' ', ' ', '6', '1', '5', ' ', ' '},
        {' ', ' ', ' ', '4', ' ', ' ', ' '},
        {'5', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '4', ' '},
    };
}

int main(int argc, char *argv[]) {

    //

    return 0;
}
