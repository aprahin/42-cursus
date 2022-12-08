/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:19:25 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/07 22:14:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hue_mod(double val)
{
	val = fmod(val, 512);
	if (val < 256)
		return (val);
	return (512 - val);
}

t_rgb	rand_rgb(void)
{
	static int	i;
	char		*rand;
	t_rgb		ret;

	rand = "yumvzsvubabncscteqvxjirmyhjdsiuqkvyxgwszjnufzklxqwecbkxnmosmsbmn\
	esmpuhyoomcmekxhrabfkutvbsomzavohgjkmyrirtyqjydvfhbzkttxkfacyygynbbrcjpr\
	bynpxovqkasurmmktgmwewddnnxvstkwfrgrhjyaeoenxppiucfwxmsqzmarakqlqhyxijwp\
	knumapshjdxjctbpffgkgifxvxragkebecblxnwvbxkqslthcjepqdqgzzkgnsusfjcsvntm\
	cozmoplflnotwbpqxokuktoropsetfutdinvkqdoefxdcyithbsyhhjhuoioucivcrzamjfn\
	kyhvidxoazlytolvcdwyhnjnbxqwdgscenzgknbxyzgkjfdzkeytixfhxetlnrzseiurgzak\
	idisrresdmeuhyxioykbqbeqocghlunksgseeytyyrymqeomgwinvrolyzubdxykbgjeczgm\
	zkkocxyixxqhmmrdqmsgbsllkghacgtsiixauizftddynyphbvhxhurpnzcfiywtanlcozss\
	brovikelpaothchjkoyiatlmovkfnaacvxnknflvdslbjnfddlvnurwwpucnwgxvjaefavrx\
	ymfnsggufzklnkabhcbjqcdjirxciqqfiwkflgukchmvzqfrzfgqcahqacbkjhstauqsfgox\
	iueghtukwtyntzrlyawsyrxqoukpaeekqvgtcxoxvqlpfoaedhbltklzkzebhqyglxyufyev\
	qdlwoisgtgpvssexgywnrxrvnklrvmaqtnbmrnygckuihjdpiwwhcdgtoiwhbbeedmobdcwm\
	qsqonlwfzqeefzhrvzdeebwikagnyjxbbxryklutbwthazkbdmmcvmxqubufhglfncvfjsdn";
	if (!i)
		i = 1;
	else
		i = (i + 10) % ft_strlen(rand);
	ret.r = (rand[i] * rand[i + 1]) % 256;
	ret.g = (rand[i + 2] * rand[i + 3]) % 256;
	ret.b = (rand[i + 4] * rand[i + 5]) % 256;
	return (ret);
}

t_rgb	itorgb(int colour)
{
	t_rgb	ret;

	ret.b = colour & 0xFF;
	ret.g = (colour >> 8) & 0xFF;
	ret.r = (colour >> 16) & 0xFF;
	return (ret);
}

int	get_colour(t_rgb base, t_rgb max, double ratio, double shift)
{
	t_rgb	colour;
	int		diff_r;
	int		diff_g;
	int		diff_b;

	if (max.r >= base.r)
		diff_r = max.r - base.r;
	else
		diff_r = 256 - base.r + max.r;
	if (max.g >= base.g)
		diff_g = max.g - base.g;
	else
		diff_g = 256 - base.g + max.g;
	if (max.b >= base.b)
		diff_b = max.b - base.b;
	else
		diff_b = 256 - base.b + max.b;
	colour.r = hue_mod((base.r + (diff_r * shift) * ratio));
	colour.g = hue_mod((base.g + (diff_g * shift) * ratio));
	colour.b = hue_mod((base.b + (diff_b * shift) * ratio));
	return (colour.r << 16 | colour.g << 8 | colour.b);
}
