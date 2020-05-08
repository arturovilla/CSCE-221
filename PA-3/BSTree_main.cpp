
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    BSTree tree1;
    for(int i =0;i<16;i++)
    {
        tree1.insert(rand()%10);
    }
    cout<<"tree1 - ";
    tree1.inorder(cout);
    cout<<endl;
    tree1.print_level_by_level(cout);
    cout<<"the number of nodes: "<<tree1.getsize()<<" Average search cost: "<<tree1.get_average_search_time()<<endl;
  // test the copy constructor
    BSTree tree2(tree1);
    cout<<"this is the copy constructor test - "<<endl;
    cout<<"tree2 - ";
    tree2.inorder(cout);
    cout<<endl;
  // test the copy assignment
    BSTree tree3;
    cout<<"this is the copy assignment test- "<<endl;
    tree3 = tree2;
    cout<<"tree3 - ";
    tree3.inorder(cout);
    cout<<endl;

    //.test the move constructors
    BSTree tree4 = tree3;
    BSTree tree5 = move(tree4);
    cout<<"this is a test of the move constructor -"<<endl;
    cout<<"tree5 - ";
    tree5.inorder(cout);
    cout<<endl;
    cout<<"tree4 - ";
    tree4.inorder(cout);
    cout<<endl;
    BSTree tree6 = move(tree5);
    cout<<"this is a test of the move assignment - "<<endl;
    cout<<"tree6 - ";
    tree6.inorder(cout);
    cout<<endl;
    cout<<"tree5 - ";
    tree5.inorder(cout);
    cout<<endl;
    cout<<endl;
    cout<<"Here i am going to do a test of the search function on the first tree for a random number"<<endl;
    cout<<*tree1.search(rand()%10);
    cout<<endl;
    cout<<tree1.search(20);
    cout<<endl;
    cout<<"Next i will print the trees that have 16 nodes or less to the screen from each tree type"<<endl;
    
//
//
//    // // // // // // // // // // // // // // // //
    cout<<"these are linear trees: "<<endl;
    for(int i = 1 ; i<=3;i++)
    {
        string filenum1 = to_string(i);
        ifstream inFile1;
        inFile1.open(filenum1+"l");
        BSTree l ;
        inFile1>>l;
        cout<<"inorder :";
        l.inorder(cout);
        cout<<endl;
        cout<<"level-by-level: "<<endl;
        l.print_level_by_level(cout);
        cout<<"Average search time: "<<l.get_average_search_time()<<endl;
        cout<<"Total number of nodes: "<<l.getsize();
        cout<<endl;
    }
//    // // // // // // // // // // // // // // // //
    cout<<"these are perfect trees: "<<endl;
    for(int i = 1 ; i<=3;i++)
    {
        string filenum2 = to_string(i);
        ifstream inFile2;
        inFile2.open(filenum2+"p");
        BSTree p ;
        inFile2>>p;
        cout<<"inorder :";
        p.inorder(cout);
        cout<<endl;
        cout<<"level-by-level: "<<endl;
        p.print_level_by_level(cout);
        cout<<"Average search time: "<<p.get_average_search_time()<<endl;
        cout<<"Total number of nodes: "<<p.getsize()<<endl;
        cout<<endl;
    }
//    // // // // // // // // // // // // // // // //
    cout<<"these are random trees: "<<endl;
    for(int i = 1 ; i<=3;i++)
    {
        string filenum3 = to_string(i);
        ifstream inFile3;
        inFile3.open(filenum3+"r");
        BSTree r ;
        inFile3>>r;
        cout<<"inorder :";
        r.inorder(cout);
        cout<<endl;
        cout<<"level-by-level: "<<endl;
        r.print_level_by_level(cout);
        cout<<"Average search time: "<<r.get_average_search_time()<<endl;
        cout<<"Total number of nodes: "<<r.getsize()<<endl;
        cout<<endl;
    }
   
    /* print trees from the first 4 files to screen */
    /*UN-COMMENT THIS BLOCK TO WRITE DATA TO FILES*/
    //to write to files of your choice

//    ofstream writeto1;
//    ofstream writeto12;
//    writeto1.open("lineartreeio.txt");
//    writeto12.open("lineartreelbl.txt");
//    cout<<"these are linear trees: "<<endl;
//    for(int i=1 ; i<=3 ; i++)
//    {
//        string filenum1 = to_string(i);
//        ifstream inFile1;
//        inFile1.open(filenum1+"l");
//        BSTree l ;
//        inFile1>>l;
//        cout<<i<<endl;
//        //
//        //writeto1<<"Number of nodes: "<<l.getsize()<<" average search cost: "<<l.get_average_search_time()<<"\n";
//        l.inorder(writeto1);
//        writeto1<<"\n";
//        l.print_level_by_level(writeto12);
//
//    }
//    writeto1.close();
//    writeto12.close();

//    ofstream writeto2;
//    writeto2.open("perfecttreeplots.txt");
//    for(int i=1 ; i<=12 ; i++)
//    {
//        string filenum2 = to_string(i);
//        ifstream inFile2;
//        inFile2.open(filenum2+"p");
//        BSTree p ;
//        inFile2>>p;
//        cout<<i<<endl;
//        writeto2<<"Number of nodes: "<<p.getsize()<<" average search cost: "<<p.get_average_search_time()<<"\n";
//    }
//    writeto2.close();
//
//    ofstream writeto3;
//    writeto3.open("randomtreeplots.txt");
//    for(int i=1 ; i<=12 ; i++)
//    {
//        string filenum3 = to_string(i);
//        ifstream inFile3;
//        inFile3.open(filenum3+"r");
//        BSTree r ;
//        inFile3>>r;
//        cout<<i<<endl;
//        writeto3<<"Number of nodes: "<<r.getsize()<<" average search cost: "<<r.get_average_search_time()<<"\n";
//    }
//     writeto3.close();

    
    
    
    
    
}

