/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 *
 * https://leetcode.com/problems/peeking-iterator/description/
 *
 * algorithms
 * Medium (42.21%)
 * Likes:    336
 * Dislikes: 233
 * Total Accepted:    82.6K
 * Total Submissions: 195.7K
 * Testcase Example:  '["PeekingIterator","next","peek","next","next","hasNext"]\n[[[1,2,3]],[],[],[],[],[]]'
 *
 * Given an Iterator class interface with methods: next() and hasNext(), design
 * and implement a PeekingIterator that support the peek() operation -- it
 * essentially peek() at the element that will be returned by the next call to
 * next().
 * 
 * Example:
 * 
 * 
 * Assume that the iterator is initialized to the beginning of the list:
 * [1,2,3].
 * 
 * Call next() gets you 1, the first element in the list.
 * Now you call peek() and it returns 2, the next element. Calling next() after
 * that still return 2. 
 * You call next() the final time and it returns 3, the last element. 
 * Calling hasNext() after that should return false.
 * 
 * 
 * Follow up: How would you extend your design to be generic and work with all
 * types, not just integer?
 * 
 */

// @lc code=start
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator
{
	struct Data;
	Data *data;

public:
	Iterator(const vector<int> &nums);
	Iterator(const Iterator &iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		_has_next = Iterator::hasNext();
		if (_has_next)
			buffer = Iterator::next();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		return buffer;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		int res = buffer;
		_has_next = Iterator::hasNext();
		if (_has_next)
			buffer = Iterator::next();
		return res;
	}

	bool hasNext() const
	{
		return _has_next;
	}

private:
	int buffer;
	bool _has_next;
};
// @lc code=end
