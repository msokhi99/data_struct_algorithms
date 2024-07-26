from hash_table_linear import hash_table_quad

t = hashing_quad()

t.insert_element(5)

print(t.hash_table)

t.insert_element(15)

print(t.hash_table)

t.insert_element(35)

print(t.hash_table)

t.insert_element(33)

print(t.hash_table)

print(t.search_element(35))
