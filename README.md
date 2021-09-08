
<div>
<p align="center">
   <img src="./.github/42.png" alt="Github-Explorer" width="500"/>
</p>
</div>
<p align="center">	
   <a href="https://www.linkedin.com/in/luiz-lima-cezario/">
      <img alt="Luiz Cezario" src="https://img.shields.io/badge/-luizCezario-682998?style=flat&logo=Linkedin&logoColor=white" />
   </a>

  <a aria-label="Completed" href="https://www.42sp.org.br/">
    <img src="https://img.shields.io/badge/42.sp-GNL-682998?logo="></img>
  </a>
  <a href="https://github.com/luizlcezario/get_next_line/commits/master">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/luizlcezario/get_next_line?color=682998">
  </a> 

  <a href="https://github.com/luizlcezario/get_next_line/stargazers">
    <img alt="Stargazers" src="https://img.shields.io/github/stars/luizlcezario/get_next_line?color=682998&logo=github">
  </a>
</p>

<div align="center">
  <sub>Get Next Line of 42. Make with ❤︎ for
        <a href="https://github.com/luizlcezario">Luiz Cezario</a> 
    </a>
  </sub>
</div>


# :pushpin: Index

* [What's this Repo?](#sparkles_What's-Libft-of-42?)
* [List of Archives](#clipboard_List-of-Archives)
* [Technologies](#computer_Technologies)
* [How to Run](#construction_How-to-Run)
* [Find a Bug? Or somenthing need to change?](#bug_Issues?)

# :sparkles: What's Get Next Line of 42?

This is a fucntion to get next line of the of a text using a Buffer.


## :clipboard: List of Archives
<h3>
Part 1
</h3>

<i>In this first part, you must re-code a set of the libc functions, as defined in their man. Your functions will need to present the same prototype and behaviors as the originals. Your functions’ names must be prefixed by “ft_”. For instance strlen becomes ft_strlen.</i>

<p align=center>
• get_next_line
• get_next_line_utils
• get_next_line
</p>

<h3 align=center>
Bonus
</h3>

<i>In this second part, you must code a set of functions that are either not included in the libc, or included in a different form. Some of these functions can be useful to write Part 1’s functions.</i>

<p align=center>
• substr
</p>

---

<h2>
The project
</h2>

### Functions from `<ctype.h>`

- [`get_next_line`](get_next_line.c)	- checks for an alphabetic character.
- [`get_next_line_utils`](get_next_line_utils.c)	- checks for a digit (0 through 9).
- [`get_next_line header`](get_next_line.h)		- checks for an alphanumeric character.

# :computer: Technologies

This Project was made with:

* [C](https://devdocs.io/)
* [Makefile](https://www.gnu.org/software/make/manual/make.html)
* [Shell](https://unixguide.readthedocs.io/en/latest/unixcheatsheet/)
* [gcc](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/)

# :construction_worker: How to Run
```bash
# If you want a Script for testing use this :
# https://github.com/luizlcezario/Libft_Test.git

# Clone the Repo
$ git clone https://github.com/luizlcezario/Libft_Test.git

# Enter in the Folder
$ cd Libft

# *************COMMANDS************ #
# run - run compile all the libtest with the your libft and run the all tests
$ make all
# clean - remove the .o and .c files 
$ make clean
# fclean - remove the .o and .c files and the .a
$ make fclean
# re - remove all files and remake all
$ make re

# after run one time the the comand all 
# you can use compile others files .c using this lib 
# and using the function of then.
$ gcc main.c -L . -lft

```


# :bug: Issues?

Please feel free **to create a new issue** with its title and description on the issues page of the [Libft](https://github.com/luizlcezario/Libft/issues) Repository. If you have already found the solution to the problem, **I would love to review your pull request**!


Give ⭐️ if you like this project, this will help me!
