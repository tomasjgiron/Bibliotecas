int controller_loadClientFromText(char* path,LinkedList* pArrayListClient);
int controller_loadSaleFromText(char* path,LinkedList* pArrayListSale);

int controller_addClient(LinkedList* pArrayListEmployee);
int controller_addSale(LinkedList* pArrayListEmployee);

int controller_modifyClient(LinkedList* pArrayListEmployee);

int controller_removeClient(LinkedList* pArrayListEmployee);
int controller_removeSale(LinkedList* pArrayListEmployee);


int controller_listClient(LinkedList* pArrayListEmployee);
int controller_listSale(LinkedList* pArrayListEmployee);


int controller_sortClient(LinkedList* pArrayListEmployee);
int controller_sortSale(LinkedList* pArrayListEmployee);


int controller_saveClientAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveSaleAsText(char* path, LinkedList* pArrayListEmployee);
