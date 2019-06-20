#include "Header.h"

vector<string> SortAmazonOrderList(vector<string> order_list)
{
	vector<string> non_prime_order_list;
	vector<string> prime_order_list;

	for (auto i = order_list.begin(); i != order_list.end(); ++i)
	{
		// "<id><delimiter><metadata>"   : delimiter = ' '
		string str = *i;
		string token_id;
		string token_metadata;
		bool is_prime = true;
		
		OrderStringParser(str, token_id, token_metadata);
		
		//cout << "metadata string: "<< token_metadata << endl;
		int index = 1;
		while (index < token_metadata.size())
		{
			if (token_metadata[index] >= '0' && token_metadata[index] <= '9')
			{
				//cout << "Non prime: " << str << endl;
				non_prime_order_list.push_back(str);
				is_prime = false;
				break;
			}				
			index++;
		}
		if (is_prime)
		{
			//cout << "prime: " << str << endl;
			prime_order_list.push_back(str);
		}
			
	}
	vector<string> result;

	sort(prime_order_list.begin(), prime_order_list.end(), comp);
	
	result.insert(result.end(), prime_order_list.rbegin(), prime_order_list.rend());
	result.insert(result.end(), non_prime_order_list.rbegin(), non_prime_order_list.rend());

	return result;
}

bool comp(string a, string b)
{
	string id1;
	string id2;
	string metadata1;
	string metadata2;


	OrderStringParser(a, id1, metadata1);
	OrderStringParser(b, id2, metadata2);
	
	size_t metadata_size1 = metadata1.size();
	size_t metadata_size2 = metadata2.size();

	size_t size = (metadata_size1 >= metadata_size2) ? metadata_size2 : metadata_size1;
	int i = 0;
	while(i<size)
	{
		//cout << "i " << i << endl;
		if (metadata1[i] > metadata2[i])
			return true;
		else if (metadata1[i] == metadata2[i])
			i++;
		else
			return false;
	}

	cout << "id must be used" << endl;

	size_t id_size1 = id1.size();
	size_t id_size2 = id2.size();

	size = (id_size1 >= id_size2) ? id_size2 : id_size1;
	i = 0;
	while (i < size)
	{
		if (id1[i] > id2[i])
			return true;
		else if (id1[i] == id2[i])
			i++;
		else
			return false;
	}

	throw "Comaparison Error";
}

void OrderStringParser(string str, string &token_id, string &token_metadata)
{
	int pos = str.find(' ');
	token_id = str.substr(0, pos);
	token_metadata = str.substr(pos);

}