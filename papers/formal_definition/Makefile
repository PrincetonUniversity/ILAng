all: ILA.pdf

ILA.pdf: *.tex #*.bib #images/*
	pdflatex -halt-on-error -pdf -bib ILA.tex
	bibtex ILA
	pdflatex -halt-on-error -pdf -bib ILA.tex
	pdflatex -halt-on-error -pdf -bib ILA.tex

clean:
	rm -f *.bbl *.blg *.log *.out *.aux *.pdf
