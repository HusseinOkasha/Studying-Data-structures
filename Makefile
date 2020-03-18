.PHONY: clean All

All:
	@echo "----------Building project:[ Queue_using_linked_list - Debug ]----------"
	@cd "Queue_using_linked_list" && "$(MAKE)" -f  "Queue_using_linked_list.mk"
clean:
	@echo "----------Cleaning project:[ Queue_using_linked_list - Debug ]----------"
	@cd "Queue_using_linked_list" && "$(MAKE)" -f  "Queue_using_linked_list.mk" clean
