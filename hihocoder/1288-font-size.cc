#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

// Return lines for a paragraphs.
int LinesForParagraphs(const int ch, const int size, const int width) {
  int ch_per_line(width / size);
  if (ch_per_line == 0) {
    return INT_MAX;
  }
  int line(ch / ch_per_line);
  if (line * ch_per_line < ch) {
    return (line + 1);
  } else {
    return line;
  }
}

int PagesForTask(const int paragraphs,
                 int* chars_per_paragraphs,
                 const int width,
                 const int height,
                 const int size) {
  // printf("PagesForTask %d %d %d %d\n", paragraphs, width, height,size);
  int lines(0);
  for (int i = 0; i < paragraphs; i++) {
    lines += LinesForParagraphs(chars_per_paragraphs[i], size, width);
  }
  int lines_per_page(height / size);
  if (lines_per_page == 0) {
    return INT_MAX;
  }
  int actual_pages(lines / lines_per_page);
  if (actual_pages * lines_per_page < lines) {
    actual_pages++;
  }
  // printf("%d %d %d %d %d\n", paragraphs, width, height,size,actual_pages);
  return actual_pages;
}

// Return the size of font for specify task
int SolutionForTask(const int paragraphs,
                    int* chars_per_paragraphs,
                    const int pages,
                    const int width,
                    const int height) {
  bool answered(false);
  int size_upper_limit(min(width, height));
  int size_lower_limit(0);
  int size((size_upper_limit + size_lower_limit) / 2);
  if (size == 0 && size + 1 <= size_upper_limit)
    size++;
  else if (size == 0)
    return 0;
  while (!answered) {
    int actual_pages =
        PagesForTask(paragraphs, chars_per_paragraphs, width, height, size);

    // cout << "Size: " <<size<<", actual page: "<<actual_pages<<", page:
    // "<<pages<<", upper: "<<size_upper_limit<<", lower: "<<size_lower_limit<<
    // endl;
    if (actual_pages > pages) {
      if (size == 1)
        return 0;
      size_upper_limit = size - 1;
      size -= max(1, (size - size_lower_limit) / 2);
      if (size < size_lower_limit)
        size++;
    } else if (size + 1 > size_upper_limit) {
      answered = true;
    } else {
      size_lower_limit = size;
      int var = max(1, (size_upper_limit - size) / 2);
      size += var;
      if (size > size_upper_limit) {
        size--;
        if (var == 1) {
          return size;
        }
      }
    }
  }
  return size;
}

int main() {
  int T(0);
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N(0);
    int P(0);
    int W(0);
    int H(0);
    scanf("%d %d %d %d", &N, &P, &W, &H);
    int chars_per_paragraphs[N];
    for (int j = 0; j < N; j++) {
      cin >> chars_per_paragraphs[j];
    }
    if (W == 0 || H == 0) {
      cout << 0 << endl;
    } else {
      int answer = SolutionForTask(N, chars_per_paragraphs, P, W, H);
      cout << answer << endl;
    }
  }
}
