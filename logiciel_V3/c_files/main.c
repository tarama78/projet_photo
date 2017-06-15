#include "incl.h"

/*
** argv[1] est le fichier avec toute les infos
**
** write in fichier_inf :
**	line 1 :
**		0 : stop
**		1 : save
**	line 2 :
**		nb_success
**	line 3 :
**		nb_error
*/

int main(int ac, char *av[])
{
    t_p		p;
    int		width;
    int		height;
    int		quit;
    char	retour[100];

    (void)width;
    (void)height;
    retour[0] = '\0';
    create_p(&p, av[1]);
    if (ac == 4)
    {
	width = my_getnbr(av[2]);
	height = my_getnbr(av[3]);
    }
    else
    {
	width = 1200;
	height = 800;
    }
    create_fen(&p, width, height);
    quit = loop(&p);
    sprintf(retour, "%d\n", quit);
    apply(&p, retour);
    p.fichier_inf = fopen(av[1], "w");
    fputs(retour, p.fichier_inf);
    fclose(p.fichier_inf);
    return (0);
}
