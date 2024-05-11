/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:31:19 by mfuente-          #+#    #+#             */
/*   Updated: 2023/10/11 10:02:55 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "general.h"

void nombre_numero(int num, char buffer[])
{
    if(num > 99)
    {
     ft_strstr()   

    }
}
int main(int argc, char *argv[])
{
    
	// Abrir el archivo en modo solo lectura
    int fd = open("numbers.dict", O_RDONLY);

    //Variables
    char buffer[1024];
    char *str;
    int num;
    ssize_t bytes_leidos;

    // Leer el contenido del archivo
	bytes_leidos = read(fd, buffer, sizeof(buffer));
    //Cerrar el archivo
    close(fd);

    //Para buscar la linea que me interesa
    str = ft_strstr(buffer, "20");
    
    int  i = 0;
    //Para descartar lo que no sean letras
    while(!((str[i] >= 'A' || str[i] >= 'Z') && (str[i] >= 'a' || str[i] <= 'z')))
    {
        i++;
    }
    //Para mostrar el nombre
    while (str[i] != '\n')
    {
        write(1, &str[i], 1);
        i++;
    }  
    num = atoi(argv[1]);

    return 0;
}