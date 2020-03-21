.PHONY: clean All

All:
	@echo "----------Building project:[ Double_ended_queue - Debug ]----------"
	@cd "Double_ended_queue" && "$(MAKE)" -f  "Double_ended_queue.mk"
clean:
	@echo "----------Cleaning project:[ Double_ended_queue - Debug ]----------"
	@cd "Double_ended_queue" && "$(MAKE)" -f  "Double_ended_queue.mk" clean
