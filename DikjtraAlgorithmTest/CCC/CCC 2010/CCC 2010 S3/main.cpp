#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test (const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str());

    myFile.close();
}

int main() {
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.1.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.2.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.3.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.4.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.5.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.6.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.7.in");
    test ("C:\\Users\\ayuan\\Documents\\Computer\\CCC\\CCC 2010\\TestFiles\\S3\\s3.8.in");

    return 0;
}
