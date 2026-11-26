
class LFUCache {
private:
    int capacity;
    int minFreq;

    // key -> value
    unordered_map<int, int> keyToValue;

    // key -> frequency
    unordered_map<int, int> keyToFreq;

    // frequency -> keys (LRU order)
    unordered_map<int, list<int>> freqToKeys;

    // key -> position in its frequency list
    unordered_map<int, list<int>::iterator> keyToIterator;

    void updateFrequency(int key) {
        int freq = keyToFreq[key];

        // Remove key from its current frequency list
        freqToKeys[freq].erase(keyToIterator[key]);

        // If this was the minimum frequency and its list is empty
        if (freq == minFreq && freqToKeys[freq].empty()) {
            minFreq++;
        }

        // Increase frequency
        keyToFreq[key]++;

        // Add key to the front of the new frequency list
        int newFreq = keyToFreq[key];
        freqToKeys[newFreq].push_front(key);

        keyToIterator[key] = freqToKeys[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValue.find(key) == keyToValue.end()) {
            return -1;
        }

        updateFrequency(key);

        return keyToValue[key];
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // If key already exists, update its value
        if (keyToValue.find(key) != keyToValue.end()) {
            keyToValue[key] = value;
            updateFrequency(key);
            return;
        }

        // If cache is full, remove LFU key
        if (keyToValue.size() == capacity) {
            int keyToRemove = freqToKeys[minFreq].back();

            freqToKeys[minFreq].pop_back();

            keyToValue.erase(keyToRemove);
            keyToFreq.erase(keyToRemove);
            keyToIterator.erase(keyToRemove);
        }

        // Insert new key with frequency 1
        keyToValue[key] = value;
        keyToFreq[key] = 1;

        freqToKeys[1].push_front(key);
        keyToIterator[key] = freqToKeys[1].begin();

        minFreq = 1;
    }
};
