# How to contribute

## Testing

Our unit tests for the features are developed based on the [Google-test](https://github.com/google/googletest.git) framework, and are automatically sent to [Coveralls.io](https://coveralls.io) for coverage analysis. 

## Submitting changes

Please send a GitHub Pull Request with a clear list of what you have done.

Always write a clear log message for your commits. One-line messages are fine for small changes, but bigger changes should look like this:

  $ git commit -m "A brief summary of the commit
  > 
  > A paragraph describing what changed and its impact."

## Coding conventions

We follow the [Google C++ Guilde Style](https://google.github.io/styleguide/cppguide.html), and use [Clang-format](https://clang.llvm.org/docs/ClangFormat.html) for consistent code.

Here are some of the most obvious conventions:

  * We indent using two spaces 
  * We use C-style Doxygen labels.
  * We ALWAYS put spaces after list items and method parameters (`[1, 2, 3]`, not `[1,2,3]`), around operators (`x += 1`, not `x+=1`), and around hash arrows.

Thanks!
