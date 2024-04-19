/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:04 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/19 14:42:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct s_print                       
{                        
      va_list args;
      int   wdt;       
      int   prc;       
      int   zero;          
      int   pnt;
      int   dash;
      int   tl;          
      int   sign;
      int   is_zero;
      int   perc; 
      int   sp;     
}    t_print;

t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->wdt = 0;  
      tab->prc = 0;
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;
      tab->sp = 0;
      return (tab);                       
}
int ft_printf(const char *format, ...)
{
   t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   ft_initialise_tab(tab)
}

