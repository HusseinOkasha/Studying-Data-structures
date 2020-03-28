.PHONY: clean All

All:
	@echo "----------Building project:[ creating_trees - Debug ]----------"
	@cd "creating_trees" && "$(MAKE)" -f  "creating_trees.mk"
clean:
	@echo "----------Cleaning project:[ creating_trees - Debug ]----------"
	@cd "creating_trees" && "$(MAKE)" -f  "creating_trees.mk" clean
