class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        destinations=set()
        departures=set()
        for path in paths:
            departures.add(path[0])
            destinations.add(path[1])
        for d in departures:
            if d in destinations:
                destinations.remove(d)
        for d in destinations:
            return d