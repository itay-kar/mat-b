#include "mat.hpp"
using namespace ariel;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <thread>
using namespace std;

void print_mat(string mat, string color_a, string color_b, char sym_a, char sym_b)
{
    cout << "\u001b[40m" << endl;
    cout << "\t\t";
    for (size_t i = 0; i < mat.size(); i++)
    {
        if (mat[i] == sym_a)
        {
            string colorized_sym = color_a;
            colorized_sym += mat[i];
            cout << colorized_sym;
        }

        else if (mat[i] == sym_b)
        {
            string colorized_sym = color_b;
            colorized_sym += mat[i];
            cout << colorized_sym;
        }

        else
            cout << mat[i] << "\t\t";
    }
};

vector<string> init_colors()
{
    vector<string> colors;
    colors.push_back("\x1B[31m");
    colors.push_back("\x1B[32m");
    colors.push_back("\x1B[33m");
    colors.push_back("\x1B[34m");
    colors.push_back("\x1B[35m");
    colors.push_back("\x1B[36m");
    colors.push_back("\x1B[37m");
    colors.push_back("\u001b[31;1m");
    colors.push_back("\u001b[32;1m");
    colors.push_back("\u001b[33;1m");
    colors.push_back("\u001b[34;1m");
    colors.push_back("\u001b[35;1m");
    colors.push_back("\u001b[36;1m");
    colors.push_back("\u001b[37;1m");
    return colors;
};

void start_music()
{
    try{
    system("aplay music.wav");
    }

    catch (exception e){
        terminate();
        return;
    }
}
int main(int argc, char const *argv[])
{

    int col, row;
    char sym_a, sym_b;
    int color_a, color_b;
    vector<string> colors = init_colors();
    cout << "Hello, Welcome to the mat printing program.\n\nThis program will print a mat in the sizes and symbols of your choice.\n"
         << endl;
    while (true)
    {
        cout << "To enter mat store press 2.\nTo print a new custom mat please enter 1 \nto exit the program please enter 0" << endl;
        int cmd = 2;
        scanf("%d", &cmd);

        if (cmd == 1)
        {
            srand(time(NULL));
            color_a = (rand() % 14);
            color_b = (rand() % 14);

            while (color_a == color_b)
            {
                color_b = (rand() % 14);
            }

            cout << color_a << "," << color_b << endl;
            cout << "Please enter Colomun size : ";
            scanf("%d", &col);

            cout << "Please enter Row size : ";
            scanf("%d", &row);

            cout << "Please enter First symbol : ";
            scanf(" %c", &sym_a);

            cout << "Please enter Second Symbol: ";
            scanf(" %c", &sym_b);

            string mat_a = mat(col, row, sym_a, sym_b);

            print_mat(mat_a, colors.at(color_a), colors.at(color_b), sym_a, sym_b);
            cout << "\x1B[0m" << endl;
        }

        else if (cmd == 0)
        {
            cout << "Bye , have a good day." << endl;
            exit(0);
        }

        else if (cmd == 2)
        {
            thread c = thread(start_music);
            sleep(1);
            cout << colors.at(3) << "\nWelcome to my mat shop! \nYou can choose a mat the you like and ask the seller for it.\n"
                 << endl;
            int num_of_mats = 20;
            int resume = 0;

            while (true)
            {
                srand(time(NULL));
                row = 2 * (rand() % 10) + 1;
                col = 2 * (rand() % 25) + 1;
                sym_a = (rand() % 93) + 33;
                sym_b = (rand() % 93) + 33;

                color_a = (rand() % 14);
                color_b = (rand() % 14);

                while (color_a == color_b)
                {
                    color_b = (rand() % 14);
                }

                string store_mat = mat(col, row, sym_a, sym_b);
                print_mat(store_mat, colors.at(color_a), colors.at(color_b), sym_a, sym_b);
                resume += 1;

                if (resume == 5)
                {
                    cout << "\x1B[0m" << endl;
                    cout << "enter 1 to see more mats or 9 to stop.\n"
                         << endl;
                    scanf(" %d", &resume);
                    if (resume == 9)
                    {
                        system("kill `pidof aplay`");
                        c.join();
                        break;
                    }
                    else
                        resume = 0;
                }

                sleep(1);
            }
        }
    }

    return 0;
}