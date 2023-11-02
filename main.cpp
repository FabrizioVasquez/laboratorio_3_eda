#include <iostream>
#include <vector>
#include <random>
#include "SStree.h"

int main() {
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1000.0, 1000.0);

    std::vector<Point> points(500, Point(50));
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 50; j++) {
            points[i][j] = dis(gen);
        }
    }

    // Insert the points into the SStree
    SsTree tree;
    for (auto& point : points) {
        tree.insert(point);
    }

    std::string filename = "sstree.dat";
    tree.saveToFile(filename);

    tree = SsTree();    // Clean the tree
    tree.loadFromFile(filename);

    //tree.print();

    std::ifstream file;
    file.open("/Users/fabriziovasquez/Downloads/UTECsstree-main/build/embbeding.dat");
    int data=0;
    std::cout<<data<<std::endl;
    file.close();


    return 0;
}
