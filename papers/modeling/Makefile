pdfs: concurrency.pdf interrupt.pdf timing.pdf

all: $(pdfs)

%.pdf: *.tex code/*
	pdflatex -halt-on-error -pdf -bib $*.tex
	pdflatex -halt-on-error -pdf -bib $*.tex
	pdflatex -halt-on-error -pdf -bib $*.tex

ILA_issues.pdf: *.tex code/* #*.bib #images/*
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex
	#bibtex ILA_issues 
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex

clean:
	rm -f *.bbl *.blg *.log *.out *.aux *.pdf
