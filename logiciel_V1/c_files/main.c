#include "incl.h"

/*
** argv[1] est le fichier avec toute les infos
*/

/*
** rename example :
**	rename_photos_name(&photos, photos.photos[3].name, "rename.jpg");
**	rename_photos_id(&photos, 3, "rename.jpg");
**delete example :
**	del_photos_name(&photos, photos.photos[2]);
**	del_photos_id(&photos, 2);
*/

int main(int ac, char *av[])
{
    t_photos	photos;
    int		width;
    int		height;

    (void)ac;
    (void)av;
    (void)photos;
    (void)width;
    (void)height;
    create_photos(&photos, av[1]);
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
    create_fen(&photos, width, height);
    loop(&photos);
    apply(&photos);
    return (0);
}
