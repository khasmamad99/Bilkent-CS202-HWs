/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : main function(s) here
*/



#include <iostream>
#include <fstream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"
#include "HuffmanCode.h"

using namespace std;

/*
int main() {
    MaxHeap mh = MaxHeap();
    cout << mh.isEmpty() << endl;
    mh.insert(5);
    mh.insert(7);
    mh.insert(2);
    mh.insert(8);
    mh.insert(15);

    cout << mh.peek() << endl;
    cout << mh.size() << endl;
    cout << mh.extractMax() << endl;
    cout << mh.peek() << endl;
    cout << mh.extractMax() << endl;

    MinHeap minh = MinHeap();
    cout << minh.isEmpty() <<  endl;
    minh.insert(5);
    minh.insert(7);
    minh.insert(2);
    minh.insert(8);
    minh.insert(15);

    cout << minh.peek() << endl;
    cout << minh.extractMin() << endl;
    cout << minh.extractMin() << endl;
    cout << minh.extractMin() << endl;

    MedianHeap medh = MedianHeap();

    medh.insert(4);
    medh.insert(5);
    medh.insert(6);
    medh.insert(7);
    medh.insert(8);
    medh.insert(9);
    medh.insert(10);
    medh.insert(11);
    medh.insert(12);

    cout << medh.findMedian() << endl;


    HuffmanHeap huff = HuffmanHeap();
    HuffmanHeap::MinHeapNode node;
    node.character = 'c';
    node.freq = 5;
    huff.insert(&node);

    HuffmanHeap::MinHeapNode node1;
    node1.character = 'a';
    node1.freq = 6;
    huff.insert(&node1);

    HuffmanHeap::MinHeapNode node2;
    node2.character = 'd';
    node2.freq = 7;
    huff.insert(&node2);

    HuffmanHeap::MinHeapNode node3;
    node3.character = 'f';
    node3.freq = 3;
    huff.insert(&node3);

    HuffmanHeap::MinHeapNode node4;
    node4.character = 'g';
    node4.freq = 1;
    huff.insert(&node4);

    cout << huff.peek()->character << endl;



    cout << huff.extractMin()->character << endl;
    cout << huff.peek()->character << endl;


    HuffmanQueue hq = HuffmanQueue();

    cout << hq.isEmpty() << endl;

    hq.insert(&node);
    hq.insert(&node1);
    hq.insert(&node2);
    hq.insert(&node3);
    hq.insert(&node4);

    cout << hq.extractMin()->character << endl;
    cout << hq.extractMin()->character << endl;
    cout << hq.extractMin()->character << endl;





    return 0;
} */

void readHuffmanTree(HuffmanHeap::MinHeapNode* root, ofstream &out, string s) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
        out << root->character << " " << s << " ";
    else {
        string sl = s + "0";
        readHuffmanTree(root->left, out, sl);

        string sr = s + "1";
        readHuffmanTree(root->right, out, sr);
    }

}

void iohandler(string in, string out) {
    string path = "(C:\\Users\\shkha\\OneDrive\\Desktop\\Courses\\Spring 18-19\\CS 202\\HW3\\)";
    string inp = in + ".txt";
    ifstream input(inp.c_str());
    if (!input.is_open())
        cout << "error: can't open the file" << endl;
    else {
        char c;
        int n, freq;
        input >> n;
        HuffmanHeap::MinHeapNode *arr[n];
        for (int i = 0; i < n; i++) {
            input >> c >> freq;
            HuffmanHeap::MinHeapNode *temp = new HuffmanHeap::MinHeapNode;
            temp->freq = freq;
            temp->character = c;
            arr[i] = temp;
        }
        HuffmanHeap::MinHeapNode* root = huffman(arr, n);
        input.close();
        ofstream output;
        string outp = out + ".txt";
        output.open(outp.c_str());
        // read the huffman tree
        string s = "";
        readHuffmanTree(root, output, s);
        output.close();
    }
}


int main() {
    iohandler("input", "output");
    return 0;
}
