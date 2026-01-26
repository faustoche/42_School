import datetime
import time

epoch_time = time.time()
today = datetime.date.today().strftime('%b %d %Y')


# On rajoute le f pour spécifier le type de format
print(f"Seconds since January 1, 1970: " f"{epoch_time:,.4f} or {epoch_time:.2e} in scientific notation")
print(today)