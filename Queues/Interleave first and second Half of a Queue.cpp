//task: one element from first half and one element from second half of queue merge them together to form a new queue

void interleaveQueue(queue<int> &q)
{
    int totalSize = q.size();
    int halfSize = totalSize / 2;

    queue<int> firstHalf;

    // Step 1: Push first half into firstHalf queue
    for (int i = 0; i < halfSize; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave elements from firstHalf and second half
    while (!firstHalf.empty()) {
        // Add one element from first half
        q.push(firstHalf.front());
        firstHalf.pop();

        // Add one element from second half (still in q)
        q.push(q.front());
        q.pop();
    }
}