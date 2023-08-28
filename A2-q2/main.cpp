#include <iostream>
#include <iomanip>

class Term {
    friend class SparseMatrix;
    int row;
    int col;
    int value;
public:

    bool operator<(const Term &rhs) {
        if(this->row == rhs.col) {
            return this->col < rhs.col;
        } else {
            return this->row < rhs.row;
        }
    }
};

class SparseMatrix {
    friend std::ostream &operator<<(std::ostream &os, const SparseMatrix &m);
    Term t[20];
public:
    void create() {
        std::cout <<"Row  " << "Column  " << "Value" << std::endl;
        std::cin >> t[0].row >> t[0].col >> t[0].value;
        for(int i=1; i<=t->value; i++) {
            std::cin >> t[i].row >> t[i].col >> t[i].value;
        }
        std::cout << std::endl;
    }

    void sort() {
        
    }

    SparseMatrix multiply(SparseMatrix m) {
        SparseMatrix newMatrix;
        int index = 0;
        
        for(int i=1; i<=t[0].value; i++) {
            for(int j=1; j<=m.t[0].value; j++) {
                for(int k=1; k<=index; k++) {
                    if (newMatrix.t[k].row == t[i].row && newMatrix.t[k].col == m.t[j].col && t[i].col == m.t[j].row) {
                        newMatrix.t[k].value += t[i].value * m.t[j].value;
                    }
                }
                if (t[i].col == m.t[j].row) {
                    index++;
                    newMatrix.t[index].row = t[i].row;
                    newMatrix.t[index].col = m.t[j].col;
                    newMatrix.t[index].value = t[i].value * m.t[j].value;
                }          
            }
        }
        newMatrix.t[0].row = this->t[0].row;
        newMatrix.t[0].col = m.t[0].col;
        newMatrix.t[0].value = index;
        return newMatrix;
    }

    

    void display() {
        std::cout << "Result Of Multiplication: " << std::endl;
        std::cout <<"Row  " << "Column  " << "Value" << std::endl;
        int i=0;
        while (t[i].row!=0) {
            std::cout << t[i].row << "     " << t[i].col << "      " << t[i].value << std::endl;
            i++;
        }
    }
};



int main() {
    std::cout << "Matrix1:" << std::endl;
    SparseMatrix m1;
    m1.create();
    std::cout << "Matrix2: " << std::endl;
    SparseMatrix m2;
    m2.create();

    SparseMatrix m3 = m1.multiply(m2);
    m3.display();
    
    return 0;
}