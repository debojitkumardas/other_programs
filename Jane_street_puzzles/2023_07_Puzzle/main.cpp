/* *********************************************
* Given a m x n ...
* If we shade a subset of the cells in the above grid, we partition the cells into orthogonally connected regions of shaded and unshaded cells. The goal of this puzzle is to shade the cells so that
*   * all regions of shaded cells are rectangular,
*   * all regions of unshaded cells are not rectangular, and
*   * all number clues in the grid give the size of the region (shaded and unshaded) that the clue is in.
* The answer to this puzzle is the product of the number os unshaded cells in each row.
*   ******************************************** */
// {' ', '6', ' ', ' ', ' ', ' ', ' '}
#include <cstdlib>
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

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j)
            std::cout << grid_data[i][j] << " ";
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        std::cerr << argc << " Command line arguments not provided. Exiting!!" << std::endl;
        exit(1);
    }
    else {
        std::cout << argv[argc - 1] << std::endl;
    }

    grid();

    return 0;
}
