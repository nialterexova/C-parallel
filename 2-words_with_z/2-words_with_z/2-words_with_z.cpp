/* 12. Считать из файла /usr/share/dict/words первые 3000 слов (если окончание файла не встретится раньше). 
Найти все слова, содержащие букву "z", используя 30 потоков.

C:\Users\Oxana\AppData\Roaming\nltk_data\corpora\words\en */

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex lockS;

void SearchZ(string word, int index) {
	if (word.find('z') == string::npos) {
		//cout << index << " " << word << "      not find  " << endl;
	}
	else {
		lockS.lock();
		cout << index << " " << word << "      zzzzzzzzzzzzzzzzzzzzzzz" << endl;
		lockS.unlock();
	}
	
}

int main()
{
	ifstream File("c:\\Users\\Oxana\\AppData\\Roaming\\nltk_data\\corpora\\words\\en");
	string word = "";
	vector <thread> Threads(30);
	int count = 0;
	while ((count < 3000) && (!File.eof())) {
		getline(File, word);
		int i = count % 30;
		Threads[(count % 30)] = thread(SearchZ, word, count);
		if (count % 30 == 29) {
			for (int i = 0; i < 30; i++) {
				Threads[i].join();
			}
		}
		lockS.lock();
		cout << count  << " " << word << endl;
		count++;
		lockS.unlock();
	}
}

