restore -dir db/
visualize -violation -property <embedded>::wrapper.%prop%
visualize -why -target %prop% -cycle %cycle% -transitive
exit

