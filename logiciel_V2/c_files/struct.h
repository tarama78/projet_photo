#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct		s_fen
{
    Uint32		coul_fond;
    SDL_Surface		*ecran;
    SDL_Surface		*img;
    SDL_Surface		*nom;
    SDL_Surface		*letter;
    SDL_Surface		*count_p;
    SDL_Rect		pos_img;
    SDL_Rect		pos_nom;
    SDL_Rect		pos_letter;
    SDL_Rect		pos_count_p;
    TTF_Font		*police;
    SDL_Color		coul_txt;
    int			size_max_txt[2];
    int			size_max_img[2];
}			t_fen;

typedef enum		e_state
{
    NO_CHANGE, DELETE, NEW_NAME
}			t_state;

typedef struct		s_gest_p
{
    char		name[100];
    t_state		state;
    char		new_name[100];
    int			letter[26];
    int			view;
}			t_gest_p;

typedef struct		s_p
{
    char		path_prog[100];
    FILE		*fichier_inf;
    char		dossier_p[100];
    char		dossier_poubelle[100];
    int			nb_p;
    t_gest_p		*p;
    int			p_act;
    int			p_change;
    int			letter_change;
    t_fen		fen;
}			t_p;

#endif
