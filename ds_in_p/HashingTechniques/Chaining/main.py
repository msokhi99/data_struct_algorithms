from hash_table_chaining import Hash_Table_Chaining

t=Hash_Table_Chaining()

t.insert_element(5)
print(t.hash_table)
t.print_elements(index=5)

print(t.delete_element(key=5))
print(t.hash_table)
