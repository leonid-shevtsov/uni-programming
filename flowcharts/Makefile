flowchart.dummy:
	mkdir -p flowchart.out
	$(foreach dot, $(shell echo flowchart/*.dot), dot -Tsvg $(dot) -o flowchart.out/$(notdir $(basename $(dot))).svg;)
	$(foreach svg, $(shell echo flowchart.out/*.svg), java -jar ~/bin/batik/batik-rasterizer.jar -dpi 300 $(svg);)

flowchart: flowchart.dummy