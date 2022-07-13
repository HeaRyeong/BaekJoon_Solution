constexpr int TABLE_SIZE = 128;

class LinkedHashBucket
{
private:
	int key;
	int hashValue;
	LinkedHashBucket* next;
public:
	LinkedHashBucket(int key, int hashValue)
	{
		this->key = key;
		this->hashValue = hashValue;
		this->next = nullptr;
	}
	int getKey()
	{
		return key;
	}
	int getHashValue()
	{
		return hashValue;
	}
	void setHashValue(int value)
	{
		this->hashValue = value;
	}
	LinkedHashBucket* getNext()
	{
		return next;
	}
	void setNext(LinkedHashBucket* next)
	{
		this->next = next;
	}
};

class HashTable
{
private:
	LinkedHashBucket** table; 
public:
	HashTable()
	{
		table = new LinkedHashBucket * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			table[i] = nullptr;
		}
	}

	int get(int key)
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			return -1;
		else
		{
			LinkedHashBucket* bucket = table[hash];
			while (bucket != nullptr && bucket->getKey() != key)
				bucket = bucket->getNext();
			if (bucket == nullptr)
				return -1;
			else
				return bucket->getHashValue();
		}
	}
	void put(int key, int value)
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			table[hash] = new LinkedHashBucket(key, value);
		else
		{
			LinkedHashBucket* bucket = table[hash];
			while (bucket->getNext() != nullptr)
				bucket = bucket->getNext();
			if (bucket->getKey() == key)
				bucket->setHashValue(value);
			else
				bucket->setNext(new LinkedHashBucket(key, value));
		}
	}
	void remove(int key)
	{
		int hash = key % TABLE_SIZE;
		if (table[hash] != nullptr)
		{
			LinkedHashBucket* prevBucket = nullptr;
			LinkedHashBucket* bucket = table[hash];

			while (bucket->getNext() != nullptr && bucket->getKey() != key)
			{
				prevBucket = bucket;
				bucket = bucket->getNext();
			}
			if (bucket->getKey() == key)
			{
				if (prevBucket == nullptr)
				{
					LinkedHashBucket* nextBucket = bucket->getNext();
					delete bucket;
					table[hash] = nextBucket;
				}
				else
				{
					LinkedHashBucket* nextBucket = bucket->getNext();
					delete bucket;
					prevBucket->setNext(nextBucket);
				}
			}
		}
	}

	~HashTable()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			if (table[i] != nullptr)
			{
				LinkedHashBucket* prevBucket = nullptr;
				LinkedHashBucket* bucket = table[i];
				while (bucket != nullptr)
				{
					prevBucket = bucket;
					bucket = bucket->getNext();
					delete prevBucket;
				}
			}
			delete[] table;
		}
	}

};