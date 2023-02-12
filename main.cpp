#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAX_COMMAND_NUMBER 100
#define MAX_ITERATOR_NUMBER 10
#define MAX_SECOND_COMMAND_LENGHT 3
#define FIXED_BEG_INDEX -1
#define FIXED_END_INDEX -2

int convert(char character) {
    return character - 48;
}

class List {
    struct block {
        //unsigned long long int* key;
        unsigned long long int key;
        block* nextElement, * previousElement;
    };
    block* beg, * end, * iterators[MAX_ITERATOR_NUMBER], * element, * temp;
    //int byteSize;

public:

    List() {
        temp = element = beg = end = NULL;
        for (int i = 0; i < MAX_ITERATOR_NUMBER; i++)
            iterators[i] = NULL;
    }

    /*List(int byteSize) {
        //this->byteSize = byteSize;
        element = beg = end = NULL;
        for (int i = 0; i < MAX_ITERATOR_NUMBER; i++)
            iterators[i] = NULL;
    }*/

    ~List() {
        if (beg) {
            while (beg != NULL) {
                temp = beg;
                beg = beg->nextElement;
                delete temp;
            }
        }
    }

    void initIterator(int index, int position) {
        if (iterators[index])
            delete iterators[index];
        iterators[index] = new block;
        if (position == FIXED_BEG_INDEX)
            iterators[index] = beg;
        else if (position == FIXED_END_INDEX)
            iterators[index] = end;
        else {
            iterators[index] = iterators[position];
        }
    }

    void moveIteratorForward(int index) {
        if (iterators[index]->nextElement == NULL)
            iterators[index] = end;
        else iterators[index] = iterators[index]->nextElement;
    }

    void moveIteratorBackward(int index) {
        if (iterators[index]->previousElement == NULL)
            iterators[index] = beg;
        else iterators[index] = iterators[index]->previousElement;
    }

    void addNumberAfter(int iterator, unsigned long long int value) {
        element = new block;
        element->key = value;
        if (beg == NULL) {
            element->nextElement = NULL;
            element->previousElement = NULL;
            beg = end = element;
        }
        else if (iterator == FIXED_END_INDEX) {
            element->nextElement = NULL;
            element->previousElement = end;
            end->nextElement = element;
            end = element;
        }
        else if (iterator == FIXED_BEG_INDEX) {
            block* tempor = beg->nextElement;
            element->nextElement = tempor;
            element->previousElement = beg;
            beg->nextElement = element;
            tempor->previousElement = element;
        }
        else {
            if (iterators[iterator]->nextElement == NULL) {
                element->nextElement = NULL;
                element->previousElement = end;
                end->nextElement = element;
                end = element;
            }
            else {
                temp = iterators[iterator]->nextElement;
                element->nextElement = temp;
                element->previousElement = iterators[iterator];
                temp->previousElement = element;
                iterators[iterator]->nextElement = element;
            }
        }
    }

    void addNumberBefore(int iterator, unsigned long long int value) {
        element = new block;
        element->key = value;
        if (beg == NULL) {
            element->nextElement = NULL;
            element->previousElement = NULL;
            beg = end = element;
        }
        else if (iterator == FIXED_BEG_INDEX) {
            element->previousElement = NULL;
            element->nextElement = beg;
            beg->previousElement = element;
            beg = element;
        }
        else if (iterator == FIXED_END_INDEX) {
            block* tempor = end->previousElement;
            element->nextElement = end;
            element->previousElement = tempor;
            end->previousElement = element;
            tempor->nextElement = element;
        }
        else {
            if (iterators[iterator]->previousElement == NULL) {
                element->previousElement = NULL;
                element->nextElement = beg;
                beg->previousElement = element;
                beg = element;
                iterators[iterator] = beg;
            }
            else {
                temp = iterators[iterator]->previousElement;
                element->nextElement = iterators[iterator];
                element->previousElement = temp;
                temp->nextElement = element;
                iterators[iterator]->previousElement = element;
            }
        }
    }

    void removeElementIterator(int position) {
        if (iterators[position]) {
            block* prev = iterators[position]->previousElement;
            temp = iterators[position];
            if (iterators[position]->nextElement == NULL) {
                if (end->previousElement == NULL) {
                    iterators[position] = NULL;
                    end = NULL;
                    beg = NULL;
                }
                else {
                    end = end->previousElement;
                    end->nextElement = NULL;
                    iterators[position] = end;
                }
            }
            else {
                iterators[position] = iterators[position]->nextElement;
                iterators[position]->previousElement = prev;
                prev->nextElement = iterators[position];
            }
            for (int i = 0; i < MAX_ITERATOR_NUMBER; i++) {
                if (iterators[i] != NULL)
                    if (i != position) {
                        if (iterators[position] == NULL) {
                            iterators[i] = NULL;
                        }
                        else if (iterators[i]->nextElement == temp->nextElement && iterators[i]->previousElement == temp->previousElement) {
                            iterators[i] = iterators[position];
                        }
                    }
            }
            delete temp;
        }
    }

    void removeElement(int position) {
        if (position == FIXED_BEG_INDEX) {
            if (beg) {
                temp = beg;
                if (beg == end)
                    end = beg = NULL;
                else {
                    beg = beg->nextElement;
                    beg->previousElement = NULL;
                }
                delete temp;
            }
        }
        else if (position == FIXED_END_INDEX) {
            if (end) {
                temp = end;
                if (beg == end)
                    end = beg = NULL;
                else {
                    end = end->previousElement;
                    end->nextElement = NULL;
                }
                delete temp;
            }
        }
        else {
            removeElementIterator(position);
        }
    }

    void printElement(int position) {
        if (position == FIXED_BEG_INDEX)
            cout << beg->key << "\n";
        else if (position == FIXED_END_INDEX)
            cout << end->key << "\n";
        else cout << iterators[position]->key << "\n";
    }

    void printAll() {
        temp = NULL;
        if (beg != NULL)
            temp = beg;
        while (temp != NULL) {
            cout << temp->key << " ";
            temp = temp->nextElement;
        }
        cout << "\n";
    }
};

void commandI(char *secondCommand, List** list) {
    int x, y;
    cin >> y >> secondCommand;
    if (strcmp(secondCommand, "BEG") == 0)
        x = FIXED_BEG_INDEX;
    else if (strcmp(secondCommand, "END") == 0)
        x = FIXED_END_INDEX;
    else x = convert(secondCommand[0]);
    (*list)->initIterator(y, x);
}

void commanddotA(char* secondCommand, List** list) {
    int x;
    unsigned long long int y;
    cin >> secondCommand >> y;
    if (strcmp(secondCommand, "BEG") == 0)
        x = FIXED_BEG_INDEX;
    else if (strcmp(secondCommand, "END") == 0)
        x = FIXED_END_INDEX;
    else x = convert(secondCommand[0]);
    (*list)->addNumberBefore(x, y);
}

void commandAdot(char* secondCommand, List** list) {
    int x;
    unsigned long long int y;
    cin >> secondCommand >> y;
    if (strcmp(secondCommand, "BEG") == 0)
        x = FIXED_BEG_INDEX;
    else if (strcmp(secondCommand, "END") == 0)
        x = FIXED_END_INDEX;
    else x = convert(secondCommand[0]);
    (*list)->addNumberAfter(x, y);
}

void commandR(char* secondCommand, List** list) {
    int x;
    cin >> secondCommand;
    if (strcmp(secondCommand, "BEG") == 0)
        x = FIXED_BEG_INDEX;
    else if (strcmp(secondCommand, "END") == 0)
        x = FIXED_END_INDEX;
    else x = convert(secondCommand[0]);
    (*list)->removeElement(x);
}

void commandP(char* secondCommand, List** list) {
    int p;
    cin >> secondCommand;
    if (strcmp(secondCommand, "ALL") == 0)
        (*list)->printAll();
    else {
        if (strcmp(secondCommand, "BEG") == 0)
            p = FIXED_BEG_INDEX;
        else if (strcmp(secondCommand, "END") == 0)
            p = FIXED_END_INDEX;
        else p = convert(secondCommand[0]);
        (*list)->printElement(p);
    }
}

int main() {
    char* command = new char[MAX_COMMAND_NUMBER];
    char* secondCommand = new char[MAX_SECOND_COMMAND_LENGHT];
    List* list = NULL;
    while (scanf("%s", command) != EOF) {
        /*if (feof(stdin) != 0) {
            break;
        }*/
        if (strcmp(command, "I") == 0) {
            //int x;
            //cin >> x;
            list = new List;
        }
        if (strcmp(command, "i") == 0) {
            commandI(secondCommand, &list);
        }
        if (strcmp(command, "+") == 0) {
            int x;
            cin >> x;
            list->moveIteratorForward(x);
        }
        if (strcmp(command, "-") == 0) {
            int x;
            cin >> x;
            list->moveIteratorBackward(x);
        }
        if (strcmp(command, ".A") == 0) {
            commanddotA(secondCommand, &list);
        }
        if (strcmp(command, "A.") == 0) {
            commandAdot(secondCommand, &list);
        }
        if (strcmp(command, "R") == 0) {
            commandR(secondCommand, &list);
        }
        if (strcmp(command, "P") == 0) {
            commandP(secondCommand, &list);
        }
    }
    if (list)
        delete list;
    delete[] command;
    delete[] secondCommand;
    return 0;
}