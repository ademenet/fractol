# Fract'ol

Fract'ol is a software displaying and allowing users to play with several fractals such as: Mandelbrot, Julia...

## Install

```bash
cd ~
git clone https://github.com/moannuo/fractol
cd fractol
make
```

## Fractals

Fract'ol allows you to display several fractals. Here some short description about their mathematical definitions.

### Mandelbrot

From [Mandelbrot](https://en.wikipedia.org/wiki/Benoit_Mandelbrot) who discovered this sequence.

The formula is:

$$ \begin{cases} z_0=0\\ f_{c}(z)=z^{2}+c \end{cases} $$

Where $f_{c}$ does not diverge.

### Julia

Julia set use the same Mandelbrot formula:

$$ \begin{cases} z_0=0\\ f_{c}(z)=z^{2}+c \end{cases} $$

This time $c$ is fixed, you do not compute it each time.

### Burning ship

It is really similar to Mandelbrot set but you take the absolute value of the imaginary and real part.

### Sources

- [Nature of code: fractals](http://natureofcode.com/book/chapter-8-fractals/)
- [Dessiner une fractale en C/C++](https://www.carnetdumaker.net/articles/dessiner-la-fractale-de-mandelbrot-en-python-et-en-cc/#dessin-dune-fractale-de-mandelbrot-en-cc)
- [Dessiner la fractale de Mandelbrot](http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html)
- [Ensemble de Mandelbrot](http://www.mathcurve.com/fractals/mandelbrot/mandelbrot.shtml)
- [Ensemble de Julia](http://www.mathcurve.com/fractals/julia/julia.shtml)
- [Rappel sur les transformations complexes](http://tanopah.jo.free.fr/ADS/bloc14/vtstranformationscomplexes.pdf)
- [Rappel sur les nombres complexes](http://ww2.cnam.fr/physique//PHR101/formules_complexes.pdf)
- [Rappel sur les nombres complexes 2](http://www.univ-orleans.fr/mapmo/membres/khaoula/enseignement2011et2012/nombre-complexe.pdf)
- [Plan complexe Wikipedia](https://fr.wikipedia.org/wiki/Plan_complexe)
