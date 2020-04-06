.PHONY: clean All

All:
	@echo "----------Building project:[ Avl_tree - Debug ]----------"
	@cd "Avl_tree" && "$(MAKE)" -f  "Avl_tree.mk"
clean:
	@echo "----------Cleaning project:[ Avl_tree - Debug ]----------"
	@cd "Avl_tree" && "$(MAKE)" -f  "Avl_tree.mk" clean
