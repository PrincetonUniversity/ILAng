all: ILA.pdf Template.pdf

ILA.pdf: *.tex #*.bib #images/*
	pdflatex -halt-on-error -pdf -bib ILA.tex
	bibtex ILA
	pdflatex -halt-on-error -pdf -bib ILA.tex
	pdflatex -halt-on-error -pdf -bib ILA.tex

Template.pdf: Template.tex
	pdflatex -halt-on-error -pdf -bib Template.tex
        #bibtex ILA
	pdflatex -halt-on-error -pdf -bib Template.tex
	pdflatex -halt-on-error -pdf -bib Template.tex
	

clean:
	rm -f *.bbl *.blg *.log *.out *.aux *.pdf
