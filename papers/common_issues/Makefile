all: ILA_issues.pdf

ILA_issues.pdf: *.tex #*.bib #images/*
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex
	#bibtex ILA_issues 
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex
	pdflatex -halt-on-error -pdf -bib ILA_issues.tex

clean:
	rm -f *.bbl *.blg *.log *.out *.aux *.pdf
