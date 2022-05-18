# generator

Single-header, ranges-compatible `generator` type built with C++20 coroutines.

[![Documentation Status](https://readthedocs.org/projects/tl-docs/badge/?version=latest)](https://tl.tartanllama.xyz/en/latest/?badge=latest)

A `generator` allows implementing sequence producers which are terse and avoid creating the whole sequence in memory.

For example, if you were to need a sequence of the first `n` integers, you *could* generate a `std::vector` of them. This implementation would be simple, but would have to produce the whole sequence in memory. To avoid this, you could instead write an iterator or range which generates them lazily. However, writing iterators and ranges comes with a lot of boilerplate. Generators have the benefits of both:

```c++
tl::generator<int> firstn(std::size_t n) {
   for (auto i = 0; i < n; ++i) {
      co_yield i;
   }
}
```

You could then use this generator like so:

```c++
for (auto i : firstn(10)) {
   std::cout << i;
}
```

Generators can also create infinite sequences:

```c++
tl::generator<int> iota(int i = 0) {
  while(true) {
    co_yield i;
    ++i;
  }
}
```

You can then pipe this to a range to process it:

```c++
for (auto i : iota() | std::views::take(10)) {
   std::cout << i;
}
```

### Compiler support
`tl::generator` has been tested on Visual Studio 2019 version 16.9 and GCC 10.

----------

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png)]("http://creativecommons.org/publicdomain/zero/1.0/")

To the extent possible under law, [Sy Brand](https://twitter.com/TartanLlama) has waived all copyright and related or neighboring rights to the `optional` library. This work is published from: United Kingdom.
