/*
** main.c for allum1 in /home/andriv_e/Documents/allum1
** 
** Made by Edwin
** Login   <andriv_e@edwin-HP-EliteBook-8560p>
** 
** Started on  Tue Feb  5 13:50:17 2013 Edwin
** Last update Sun Feb 17 23:19:20 2013 theSilverNeph
*/

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	who_begins()
{
  char	choice;

  printw("Do you want to play first ? y/N\n");
  choice = getch();
  if (choice == 'y')
    {
      printw("You choose to play first\n");
      player(16);
    }
  else if (choice == 'N')
    {
      printw("You choose to play after the IA\n");
      comp_ia(16);
    }
  else
    {
      printw("Choose y or N please\n");
      who_begins();
    }
  return (0);
}

int	player(int test)
{
  int	taken;

  while (test > 0)
    {
      printw("You are on the row which have %d matches left\n", test);
      printw("How many matches do you want to take ?\n");
      taken = getch() - '0';
      printw("You choose to remove %d matches\n", taken);
      if (taken == 0)
	printw("Don't cheat !\n");
      else
	{
	  test -= taken;
	  if (test <= 0)
	    {
	      printw("You LOOSE !\nPress any key to quit\n");
	      getch();
	      return (0);
	    }
	  comp_ia(test);
	}
    }
  return (0);
}

int	comp_ia(int test)
{
  int	taken_ia;

  taken_ia = 3;
  printw("The IA choose to remove %d matches\n", taken_ia);
  if (test > 0)
    test -= taken_ia;
  if (test <= 0)
    {
      printw("You WIN !\nPress any key to quit\n");
      getch();
    }
  player(test);
}


int	main(int ac, char **av)
{
  initscr();
  raw();
  noecho();
  who_begins();
  endwin();
  return (0);
}
