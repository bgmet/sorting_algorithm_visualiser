# Sorting algorithms visualiser

Typical animation that you are familiar with, seen on youtube. I want to recreate that to get closer to sorting algorithms and to do other things than doomscroll and youtube rot.

## Approach

Since this project is in c++, I will use classes:

- Window handler class: draw, clear, update etc

- Sorting algorithm class: vector, get functions to draw etc

- Add colors to show which is the current number and with which other element do we compare it

## Implemented algorithms

- [x] Bubble Sort

- [x] Insertion Sort

- [x] Selection Sort

- [x] Gnome Sort

- [x] Merge Sort

- [X] Quick Sort

- [ ] Heap Sort // way too hard for now

## Embellishment

- [ ] Add a better color system

- [X] Provide some information on the screen: number of comparisons etc

- [X] Timer for the sort

- [ ] Add thickness to the lines: if stick thick enough, make it thinner, black background will take care of the rest

- [X] Implement a shuffling algorithm: in order to have unique simulations

- [X] `dynamic_cast` for the size of values on base case (`stack_empty_once`): right now set w/ constant `99`