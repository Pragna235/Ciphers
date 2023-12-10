// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isn't
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = key.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		char x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		char x = (cipher_text[i] - key[i] + 26) %26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main()
{
    int option;
    cout<<"Enter 0 for Encryption and 1 for Decryption : ";
    cin>>option;

    string str;
    string keyword;
    string key;
    string cipher_text;

	if(!option)
    {

        cout<<endl<<"Enter Plain Text : ";
        cin>>str;

        cout<<endl<<"Enter the Keyword : ";
        cin>>keyword;

        key = generateKey(str, keyword);
        cout<<endl<<"Your generated key : "<<key<<endl;

        cipher_text = cipherText(str, key);
        cout << endl <<"Encrypted Message : "<< cipher_text << "\n";
    }
    else
    {
        cout<<endl<<"Enter Encrypted Message : ";
        cin>>cipher_text;

        cout<<endl<<"Enter the Keyword : ";
        cin>>keyword;

        key = generateKey(cipher_text, keyword);

        cout << endl<<"Decrypted Message : "<< originalText(cipher_text, key)<<endl;
    }



	return 0;
}

