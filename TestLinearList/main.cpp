#include <iostream>
#include "seqlist.h"
using namespace std;
int main()
{
    cout << "Begining of DataType learning:" << endl;
    SeqList<int>*  seqlist = NULL;
    seqlist = new SeqList<int>();
    seqlist->input();
    seqlist->output();
    return 0;
}
