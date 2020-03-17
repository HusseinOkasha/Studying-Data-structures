.PHONY: clean All

All:
	@echo "----------Building project:[ Queues - Debug ]----------"
	@cd "Queues" && "$(MAKE)" -f  "Queues.mk"
clean:
	@echo "----------Cleaning project:[ Queues - Debug ]----------"
	@cd "Queues" && "$(MAKE)" -f  "Queues.mk" clean
