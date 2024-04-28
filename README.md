# sorting_algorithms
A self-learn project where I implement some classic sorting algorithms: Selection Sort, Merge Sort, Quick Sort, Heap Sort

Implement on C++

File [selflearn_SortingAlorithms.cpp](https://github.com/nhidang912/sorting_algorithms/blob/main/selflearn_SortingAlorithms.cpp) contains:
- Class Solution:
  - selection_Sort(vector<int>&): return the ascending sorted vector by Selection Sort algorithms
  - merge_Sort(vector<int>&)
  - quick_Sort(vector<int>&)
  - heap_Sort(vector<int>&)
- Class Testing:
  - sorting_random():
    - create 5 random vectors which length: 10, 100, 1000, 10000, 100000p
    - sort 5 vector above (current file is using Heap Sort, to change type of sort algorithm, please modify private function sortingType())
    - print the validate result of vectors above & number of comparation within the algorthim
  - sorting_someUnique(): create 3 vectors which only contains some unique values, then sort & print as sorting_random()
  - sorting_alreadySort(): create 4 vectors which almost/already sorted by ascending/descending order, then sort & print as sorting_random() 
