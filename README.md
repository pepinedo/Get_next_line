<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/get_next_line-light.png?raw=true#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/get_next_line-dark.png?raw=true#gh-dark-mode-only" alt="Banner (oscuro)" />
    <br>
    This project is about programming a function that returns a line read from a file descriptor.
    <br>
    <a href='https://profile.intra.42.fr/users/ppinedo-' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/>
    </a>
</div>

---

# Mandatory part

<table>
  <tr>
    <th>Function name</th>
    <td><em>get_next_line</em></td>
  </tr>
  <tr>
	<th>Prototype</th>
	<td><code>char *get_next_line(int fd);</code></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td><code>get_next_line.c</code>, <code>get_next_line_utils.c</code>, <code>get_next_line.h</code></td>
  </tr>
  <tr>
    <th>Parameters</th>
    <td><code>fd</code>: The file descriptor to read from</td>
  </tr>
  <tr>
	<th>Return value</th>
	<td><em>Read line:</em> correct behaviour<br><em>NULL</em>: there is nothing else to read, or an error ocurred</td>
  </tr>
  <tr>
    <th>External functions</th>
    <td><code>read</code>, <code>malloc</code>, <code>free</code></td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Write a function that returns a line read from a file descriptor</td>
  </tr>
</table>

## Observations

- Repeated calls (e.g., using a loop) to your ``get_next_line()`` function should let
you read the text file pointed to by the file descriptor, __one line at a time__.
- Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return ``NULL``.
- Make sure that your function works as expected both when reading a file and when
reading from the standard input.
- __Please note__ that the returned line should include the terminating ``\n`` character,
except if the end of file was reached and does not end with a ``\n`` character.
- Your header file ``get_next_line.h`` must at least contain the prototype of the
``get_next_line()`` function.
- Add all the helper functions you need in the ``get_next_line_utils.c`` file.
- Because you will have to read files in ``get_next_line()``, add this option to your
compiler call: ``-D BUFFER_SIZE=n``
It will define the buffer size for ``read()``.
The buffer size value will be modified by your peer-evaluators and the _Moulinette_
in order to test your code.
- You will compile your code as follows (a buffer size of __42__ is used as an example):
``cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c``
- We consider that ``get_next_line()`` has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas ``read()`` didn’t reach the
end of file.
- We also consider that ``get_next_line()`` has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

## Forbidden

- You are not allowed to use your ``libft`` in this project.
- ``lseek()`` is forbidden.
- Global variables are forbidden.

# Bonus part

This project is straightforward and doesn’t allow complex bonuses. However, we trust
your creativity. If you completed the mandatory part, give a try to this bonus part.

## Requirements

- Develop ``get_next_line()`` using only one static variable.
- Your ``get_next_line()`` can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call ``get_next_line()`` to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.

Append the ``_bonus.[c\h]`` suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:
- ``get_next_line_bonus.c``
- ``get_next_line_bonus.h``
- ``get_next_line_utils_bonus.c``